#pragma once
#include <iostream>
#include <memory>

template <class R, class P>
class FunctorImpl {
protected:

public:
	virtual R operator()(P &p) = 0;

	virtual ~FunctorImpl() {}

};

// functor
template <class R, class P>
class Functor {


public:
	typedef R ResultType;
	typedef P ParmType;

	typedef FunctorImpl<ResultType, ParmType> Impl;

	Functor();

	 Functor(std::unique_ptr<Impl> pImpl) :spImpl_(pImpl) {
	}

	ResultType operator()(ParmType &p) {
		return (*spImpl_)(p);
	}

	virtual ~Functor() ;
protected:

	std::unique_ptr<Impl> spImpl_;

};
