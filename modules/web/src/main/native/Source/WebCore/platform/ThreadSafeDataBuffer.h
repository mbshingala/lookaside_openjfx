/*
 * Copyright (C) 2015 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef ThreadSafeDataBuffer_h
#define ThreadSafeDataBuffer_h

#include <wtf/ThreadSafeRefCounted.h>
#include <wtf/Vector.h>

namespace WebCore {

class ThreadSafeDataBuffer;

class ThreadSafeDataBufferImpl : public ThreadSafeRefCounted<ThreadSafeDataBufferImpl> {
friend class ThreadSafeDataBuffer;
private:
    enum AdoptVectorTag { AdoptVector };
    ThreadSafeDataBufferImpl(Vector<uint8_t>& data, AdoptVectorTag)
    {
        m_data.swap(data);
    }

    ThreadSafeDataBufferImpl(const Vector<uint8_t>& data)
        : m_data(data)
    {
    }

    Vector<uint8_t> m_data;
};

class ThreadSafeDataBuffer {
public:
    static ThreadSafeDataBuffer adoptVector(Vector<uint8_t>& data)
    {
        return ThreadSafeDataBuffer(data, ThreadSafeDataBufferImpl::AdoptVector);
    }

    static ThreadSafeDataBuffer copyVector(const Vector<uint8_t>& data)
    {
        return ThreadSafeDataBuffer(data);
    }

    ThreadSafeDataBuffer()
    {
    }

    const Vector<uint8_t>* data() const
    {
        return m_impl ? &m_impl->m_data : nullptr;
    }

private:
    explicit ThreadSafeDataBuffer(Vector<uint8_t>& data, ThreadSafeDataBufferImpl::AdoptVectorTag tag)
    {
        m_impl = adoptRef(new ThreadSafeDataBufferImpl(data, tag));
    }

    explicit ThreadSafeDataBuffer(const Vector<uint8_t>& data)
    {
        m_impl = adoptRef(new ThreadSafeDataBufferImpl(data));
    }

    RefPtr<ThreadSafeDataBufferImpl> m_impl;
};

} // namespace WebCore

#endif // ThreadSafeDataBuffer_h
