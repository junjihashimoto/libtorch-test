#include <ATen/core/List.h>
#include <ATen/core/ivalue.h>
#include <vector>


void deleteC10ListTensor(c10::List<at::Tensor>* obj){
  delete obj;
}

int test(){
  return 0;
}

c10::List<at::IValue>* newC10ListIValue(at::IValue* elem){ return new c10::impl::GenericList(elem->type()); }

c10::List<at::Tensor>* newC10ListTensor(){ return new c10::List<at::Tensor>(); }

c10::List<c10::optional<at::Tensor>>* newC10ListOptionalTensor(){ return new c10::List<c10::optional<at::Tensor>>(); }

c10::List<double>* newC10ListDouble(){ return new c10::List<double>(); }

c10::List<int64_t>* newC10ListInt(){ return new c10::List<int64_t>(); }

c10::List<bool>* newC10ListBool(){ return new c10::List<bool>(); }

bool c10ListIValue_empty(c10::List<at::IValue>* obj){ return (*obj).empty(); }

bool c10ListTensor_empty(c10::List<at::Tensor>* obj){ return (*obj).empty(); }

bool c10ListOptionalTensor_empty(c10::List<c10::optional<at::Tensor>>* obj){ return (*obj).empty(); }

bool c10ListDouble_empty(c10::List<double>* obj){ return (*obj).empty(); }

bool c10ListInt_empty(c10::List<int64_t>* obj){ return (*obj).empty(); }

bool c10ListBool_empty(c10::List<bool>* obj){ return (*obj).empty(); }

size_t c10ListIValue_size(c10::List<at::IValue>* obj){ return (*obj).size(); }

size_t c10ListTensor_size(c10::List<at::Tensor>* obj){ return (*obj).size(); }

size_t c10ListOptionalTensor_size(c10::List<c10::optional<at::Tensor>>* obj){ return (*obj).size(); }

size_t c10ListDouble_size(c10::List<double>* obj){ return (*obj).size(); }

size_t c10ListInt_size(c10::List<int64_t>* obj){ return (*obj).size(); }

size_t c10ListBool_size(c10::List<bool>* obj){ return (*obj).size(); }

at::IValue* c10ListIValue_at(c10::List<at::IValue>* obj,size_t s){ return new at::IValue((*obj)[s]); }

at::Tensor* c10ListTensor_at(c10::List<at::Tensor>* obj,size_t s){ return new at::Tensor((*obj)[s]); }

at::Tensor* c10ListOptionalTensor_at(c10::List<c10::optional<at::Tensor>>* obj,size_t s){ c10::List<c10::optional<at::Tensor>>& list = *obj; c10::optional<at::Tensor> v = list[s]; return new at::Tensor(v.value());  }

double c10ListDouble_at(c10::List<double>* obj,size_t s){ return ((*obj)[s]); }

int64_t c10ListInt_at(c10::List<int64_t>* obj,size_t s){ return (int64_t)((*obj)[s]); }

bool c10ListBool_at(c10::List<bool>* obj,size_t s){ return ((*obj)[s]); }

void c10ListIValue_push_back(c10::List<at::IValue>* obj,at::IValue* v){  (*obj).push_back(*v); }

void c10ListTensor_push_back(c10::List<at::Tensor>* obj,at::Tensor* v){  (*obj).push_back(*v); }

void c10ListOptionalTensor_push_back(c10::List<c10::optional<at::Tensor>>* obj,at::Tensor* v){  (*obj).push_back(*v); }

void c10ListDouble_push_back(c10::List<double>* obj,double v){  (*obj).push_back(v); }

void c10ListInt_push_back(c10::List<int64_t>* obj,int64_t v){  (*obj).push_back(v); }

void c10ListBool_push_back(c10::List<bool>* obj,bool v){  (*obj).push_back(v); }



