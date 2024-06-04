#include <ATen/core/List.h>
#include <ATen/core/ivalue.h>
#include <vector>



void deleteC10Dict(c10::Dict<at::IValue,at::IValue>* obj){
  delete obj;
}

// int test(){
//   return 0;
// }


c10::Dict<at::IValue,at::IValue>* newC10Dict(at::IValue* key, at::IValue* value){
  return new c10::impl::GenericDict(key->type(),value->type());
}

bool c10Dict_empty(c10::Dict<at::IValue,at::IValue>* _obj){ return _obj->empty(); }

size_t c10Dict_size(c10::Dict<at::IValue,at::IValue>* _obj){ return _obj->size(); }

at::IValue* c10Dict_at(c10::Dict<at::IValue,at::IValue>* _obj, at::IValue* _s){ return new at::IValue(_obj->at(*_s)); }

void c10Dict_insert(c10::Dict<at::IValue,at::IValue>* _obj,at::IValue* key, at::IValue* value){
    _obj->insert(key,value);
}
  
// c10Dict_toList :: Ptr (C10Dict '(IValue,IValue)) -> IO [(Ptr IValue,Ptr IValue)]
// c10Dict_toList _obj = do
//   let new = [C.throwBlock| std::vector<std::array<at::IValue,2>>* {
//               auto obj = *$(c10::Dict<at::IValue,at::IValue>* _obj);
//               auto ret = new std::vector<std::array<at::IValue,2> >();
//               for(auto i = obj.begin() ; i != obj.end() ; i++){
//                 ret->push_back({i->key(),i->value()});
//               }
//               return ret;
//              }|]
//       free dat = [C.throwBlock| void {
//               delete $(std::vector<std::array<at::IValue,2>>* dat);
//              }|]
//   bracket new free $ \dat -> do
//     size <- [C.throwBlock| int64_t { return (long int)$(std::vector<std::array<at::IValue,2>>* dat)->size();}|]
//     ret <- forM [0..(size-1)] $ \i -> do
//       key <- [C.throwBlock| at::IValue* { return new at::IValue($(std::vector<std::array<at::IValue,2>>* dat)->at($(int64_t i))[0]);}|]
//       val <- [C.throwBlock| at::IValue* { return new at::IValue($(std::vector<std::array<at::IValue,2>>* dat)->at($(int64_t i))[1]);}|]
//       return (key,val)
//     return ret
