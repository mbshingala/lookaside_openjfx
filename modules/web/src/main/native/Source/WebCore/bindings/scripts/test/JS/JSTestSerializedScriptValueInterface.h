/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#ifndef JSTestSerializedScriptValueInterface_h
#define JSTestSerializedScriptValueInterface_h

#if ENABLE(Condition1) || ENABLE(Condition2)

#include "JSDOMWrapper.h"
#include "TestSerializedScriptValueInterface.h"
#include <wtf/NeverDestroyed.h>

namespace WebCore {

class JSTestSerializedScriptValueInterface : public JSDOMWrapper<TestSerializedScriptValueInterface> {
public:
    typedef JSDOMWrapper<TestSerializedScriptValueInterface> Base;
    static JSTestSerializedScriptValueInterface* create(JSC::Structure* structure, JSDOMGlobalObject* globalObject, Ref<TestSerializedScriptValueInterface>&& impl)
    {
        JSTestSerializedScriptValueInterface* ptr = new (NotNull, JSC::allocateCell<JSTestSerializedScriptValueInterface>(globalObject->vm().heap)) JSTestSerializedScriptValueInterface(structure, *globalObject, WTFMove(impl));
        ptr->finishCreation(globalObject->vm());
        return ptr;
    }

    static const bool hasStaticPropertyTable = false;

    static JSC::JSObject* createPrototype(JSC::VM&, JSC::JSGlobalObject*);
    static JSC::JSObject* getPrototype(JSC::VM&, JSC::JSGlobalObject*);
    static TestSerializedScriptValueInterface* toWrapped(JSC::JSValue);
    static void destroy(JSC::JSCell*);

    DECLARE_INFO;

    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

    static JSC::JSValue getConstructor(JSC::VM&, const JSC::JSGlobalObject*);
    mutable JSC::WriteBarrier<JSC::Unknown> m_cachedValue;
    mutable JSC::WriteBarrier<JSC::Unknown> m_cachedReadonlyValue;
    static void visitChildren(JSCell*, JSC::SlotVisitor&);

protected:
    JSTestSerializedScriptValueInterface(JSC::Structure*, JSDOMGlobalObject&, Ref<TestSerializedScriptValueInterface>&&);

    void finishCreation(JSC::VM& vm)
    {
        Base::finishCreation(vm);
        ASSERT(inherits(info()));
    }

};

class JSTestSerializedScriptValueInterfaceOwner : public JSC::WeakHandleOwner {
public:
    virtual bool isReachableFromOpaqueRoots(JSC::Handle<JSC::Unknown>, void* context, JSC::SlotVisitor&);
    virtual void finalize(JSC::Handle<JSC::Unknown>, void* context);
};

inline JSC::WeakHandleOwner* wrapperOwner(DOMWrapperWorld&, TestSerializedScriptValueInterface*)
{
    static NeverDestroyed<JSTestSerializedScriptValueInterfaceOwner> owner;
    return &owner.get();
}

inline void* wrapperKey(TestSerializedScriptValueInterface* wrappableObject)
{
    return wrappableObject;
}

JSC::JSValue toJS(JSC::ExecState*, JSDOMGlobalObject*, TestSerializedScriptValueInterface*);
inline JSC::JSValue toJS(JSC::ExecState* state, JSDOMGlobalObject* globalObject, TestSerializedScriptValueInterface& impl) { return toJS(state, globalObject, &impl); }
JSC::JSValue toJSNewlyCreated(JSC::ExecState*, JSDOMGlobalObject*, TestSerializedScriptValueInterface*);


} // namespace WebCore

#endif // ENABLE(Condition1) || ENABLE(Condition2)

#endif