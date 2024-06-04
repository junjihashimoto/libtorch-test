#include <ATen/core/List.h>
#include <ATen/core/ivalue.h>
#include <vector>

extern c10::Dict<at::IValue,at::IValue>* newC10Dict(at::IValue* key, at::IValue* value);
extern c10::List<at::Tensor>* newC10ListTensor();

int
main(){
  c10::Dict<at::IValue,at::IValue> *d = newC10Dict(NULL,NULL);
  c10::List<at::Tensor> *l = newC10ListTensor();
  delete l;
  delete d;
  return 0;
}
