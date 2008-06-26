
#ifndef __MOCKCPP_CHAINABLE_MOCK_METHOD_CORE_H
#define __MOCKCPP_CHAINABLE_MOCK_METHOD_CORE_H

#include <mockcpp.h>
#include <Namespace.h>
#include <Method.h>

#include <string>

MOCKCPP_NS_START

class Any;
class Namespace;
class Stub;
class ChainableMockMethodCoreImpl;
class SelfDescribe;
class InvokedRecorder;

class ChainableMockMethodCore
		: public Method
		, public Namespace
{
public:

    ChainableMockMethodCore(const std::string& name, const Namespace* ns);
    ~ChainableMockMethodCore();

    std::string& getName(void) const;
    Namespace* getNamespace() const;

    Any invoke( const RefAny& p1 
              , const RefAny& p2
              , const RefAny& p3
              , const RefAny& p4
              , const RefAny& p5
              , const RefAny& p6
              , const RefAny& p7
              , const RefAny& p8
              , const RefAny& p9
              , const RefAny& p10
              , const RefAny& p11
              , const RefAny& p12
              , SelfDescribe* &resultProvider);

    void setDefaultStub(Stub* stub);

    WorkingBuilder stubs();
    WorkingBuilder expects(Matcher* matcher);
    DefaultBuilder defaults();

    void reset();

    void verify();

public:

    InvocationMocker* getInvocationMocker(const std::string& id);
    void addInvocationMocker(InvocationMocker* mocker);

private:

    ChainableMockMethodCoreImpl* This;
};

MOCKCPP_NS_END

#endif

