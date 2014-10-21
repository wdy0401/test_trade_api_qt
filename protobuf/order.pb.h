// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: order.proto

#ifndef PROTOBUF_order_2eproto__INCLUDED
#define PROTOBUF_order_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace TRANS_ORDER {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_order_2eproto();
void protobuf_AssignDesc_order_2eproto();
void protobuf_ShutdownFile_order_2eproto();

class order;
class orders;

enum ebuysell {
  buy = 0,
  sell = 1
};
bool ebuysell_IsValid(int value);
const ebuysell ebuysell_MIN = buy;
const ebuysell ebuysell_MAX = sell;
const int ebuysell_ARRAYSIZE = ebuysell_MAX + 1;

const ::google::protobuf::EnumDescriptor* ebuysell_descriptor();
inline const ::std::string& ebuysell_Name(ebuysell value) {
  return ::google::protobuf::internal::NameOfEnum(
    ebuysell_descriptor(), value);
}
inline bool ebuysell_Parse(
    const ::std::string& name, ebuysell* value) {
  return ::google::protobuf::internal::ParseNamedEnum<ebuysell>(
    ebuysell_descriptor(), name, value);
}
// ===================================================================

class order : public ::google::protobuf::Message {
 public:
  order();
  virtual ~order();

  order(const order& from);

  inline order& operator=(const order& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const order& default_instance();

  void Swap(order* other);

  // implements Message ----------------------------------------------

  order* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const order& from);
  void MergeFrom(const order& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required string symbol = 1;
  inline bool has_symbol() const;
  inline void clear_symbol();
  static const int kSymbolFieldNumber = 1;
  inline const ::std::string& symbol() const;
  inline void set_symbol(const ::std::string& value);
  inline void set_symbol(const char* value);
  inline void set_symbol(const char* value, size_t size);
  inline ::std::string* mutable_symbol();
  inline ::std::string* release_symbol();
  inline void set_allocated_symbol(::std::string* symbol);

  // optional double price = 2;
  inline bool has_price() const;
  inline void clear_price();
  static const int kPriceFieldNumber = 2;
  inline double price() const;
  inline void set_price(double value);

  // required int32 size = 3;
  inline bool has_size() const;
  inline void clear_size();
  static const int kSizeFieldNumber = 3;
  inline ::google::protobuf::int32 size() const;
  inline void set_size(::google::protobuf::int32 value);

  // required .TRANS_ORDER.ebuysell buysell = 4;
  inline bool has_buysell() const;
  inline void clear_buysell();
  static const int kBuysellFieldNumber = 4;
  inline ::TRANS_ORDER::ebuysell buysell() const;
  inline void set_buysell(::TRANS_ORDER::ebuysell value);

  // optional int32 date = 5 [default = 0];
  inline bool has_date() const;
  inline void clear_date();
  static const int kDateFieldNumber = 5;
  inline ::google::protobuf::int32 date() const;
  inline void set_date(::google::protobuf::int32 value);

  // optional double begintm = 6 [default = 0];
  inline bool has_begintm() const;
  inline void clear_begintm();
  static const int kBegintmFieldNumber = 6;
  inline double begintm() const;
  inline void set_begintm(double value);

  // optional double endtm = 7 [default = 0];
  inline bool has_endtm() const;
  inline void clear_endtm();
  static const int kEndtmFieldNumber = 7;
  inline double endtm() const;
  inline void set_endtm(double value);

  // optional bool marketorder = 8 [default = false];
  inline bool has_marketorder() const;
  inline void clear_marketorder();
  static const int kMarketorderFieldNumber = 8;
  inline bool marketorder() const;
  inline void set_marketorder(bool value);

  // @@protoc_insertion_point(class_scope:TRANS_ORDER.order)
 private:
  inline void set_has_symbol();
  inline void clear_has_symbol();
  inline void set_has_price();
  inline void clear_has_price();
  inline void set_has_size();
  inline void clear_has_size();
  inline void set_has_buysell();
  inline void clear_has_buysell();
  inline void set_has_date();
  inline void clear_has_date();
  inline void set_has_begintm();
  inline void clear_has_begintm();
  inline void set_has_endtm();
  inline void clear_has_endtm();
  inline void set_has_marketorder();
  inline void clear_has_marketorder();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* symbol_;
  double price_;
  ::google::protobuf::int32 size_;
  int buysell_;
  double begintm_;
  ::google::protobuf::int32 date_;
  bool marketorder_;
  double endtm_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(8 + 31) / 32];

  friend void  protobuf_AddDesc_order_2eproto();
  friend void protobuf_AssignDesc_order_2eproto();
  friend void protobuf_ShutdownFile_order_2eproto();

  void InitAsDefaultInstance();
  static order* default_instance_;
};
// -------------------------------------------------------------------

class orders : public ::google::protobuf::Message {
 public:
  orders();
  virtual ~orders();

  orders(const orders& from);

  inline orders& operator=(const orders& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const orders& default_instance();

  void Swap(orders* other);

  // implements Message ----------------------------------------------

  orders* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const orders& from);
  void MergeFrom(const orders& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .TRANS_ORDER.order order_list = 1;
  inline int order_list_size() const;
  inline void clear_order_list();
  static const int kOrderListFieldNumber = 1;
  inline const ::TRANS_ORDER::order& order_list(int index) const;
  inline ::TRANS_ORDER::order* mutable_order_list(int index);
  inline ::TRANS_ORDER::order* add_order_list();
  inline const ::google::protobuf::RepeatedPtrField< ::TRANS_ORDER::order >&
      order_list() const;
  inline ::google::protobuf::RepeatedPtrField< ::TRANS_ORDER::order >*
      mutable_order_list();

  // @@protoc_insertion_point(class_scope:TRANS_ORDER.orders)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::TRANS_ORDER::order > order_list_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_order_2eproto();
  friend void protobuf_AssignDesc_order_2eproto();
  friend void protobuf_ShutdownFile_order_2eproto();

  void InitAsDefaultInstance();
  static orders* default_instance_;
};
// ===================================================================


// ===================================================================

// order

// required string symbol = 1;
inline bool order::has_symbol() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void order::set_has_symbol() {
  _has_bits_[0] |= 0x00000001u;
}
inline void order::clear_has_symbol() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void order::clear_symbol() {
  if (symbol_ != &::google::protobuf::internal::kEmptyString) {
    symbol_->clear();
  }
  clear_has_symbol();
}
inline const ::std::string& order::symbol() const {
  return *symbol_;
}
inline void order::set_symbol(const ::std::string& value) {
  set_has_symbol();
  if (symbol_ == &::google::protobuf::internal::kEmptyString) {
    symbol_ = new ::std::string;
  }
  symbol_->assign(value);
}
inline void order::set_symbol(const char* value) {
  set_has_symbol();
  if (symbol_ == &::google::protobuf::internal::kEmptyString) {
    symbol_ = new ::std::string;
  }
  symbol_->assign(value);
}
inline void order::set_symbol(const char* value, size_t size) {
  set_has_symbol();
  if (symbol_ == &::google::protobuf::internal::kEmptyString) {
    symbol_ = new ::std::string;
  }
  symbol_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* order::mutable_symbol() {
  set_has_symbol();
  if (symbol_ == &::google::protobuf::internal::kEmptyString) {
    symbol_ = new ::std::string;
  }
  return symbol_;
}
inline ::std::string* order::release_symbol() {
  clear_has_symbol();
  if (symbol_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = symbol_;
    symbol_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void order::set_allocated_symbol(::std::string* symbol) {
  if (symbol_ != &::google::protobuf::internal::kEmptyString) {
    delete symbol_;
  }
  if (symbol) {
    set_has_symbol();
    symbol_ = symbol;
  } else {
    clear_has_symbol();
    symbol_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional double price = 2;
inline bool order::has_price() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void order::set_has_price() {
  _has_bits_[0] |= 0x00000002u;
}
inline void order::clear_has_price() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void order::clear_price() {
  price_ = 0;
  clear_has_price();
}
inline double order::price() const {
  return price_;
}
inline void order::set_price(double value) {
  set_has_price();
  price_ = value;
}

// required int32 size = 3;
inline bool order::has_size() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void order::set_has_size() {
  _has_bits_[0] |= 0x00000004u;
}
inline void order::clear_has_size() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void order::clear_size() {
  size_ = 0;
  clear_has_size();
}
inline ::google::protobuf::int32 order::size() const {
  return size_;
}
inline void order::set_size(::google::protobuf::int32 value) {
  set_has_size();
  size_ = value;
}

// required .TRANS_ORDER.ebuysell buysell = 4;
inline bool order::has_buysell() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void order::set_has_buysell() {
  _has_bits_[0] |= 0x00000008u;
}
inline void order::clear_has_buysell() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void order::clear_buysell() {
  buysell_ = 0;
  clear_has_buysell();
}
inline ::TRANS_ORDER::ebuysell order::buysell() const {
  return static_cast< ::TRANS_ORDER::ebuysell >(buysell_);
}
inline void order::set_buysell(::TRANS_ORDER::ebuysell value) {
  assert(::TRANS_ORDER::ebuysell_IsValid(value));
  set_has_buysell();
  buysell_ = value;
}

// optional int32 date = 5 [default = 0];
inline bool order::has_date() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void order::set_has_date() {
  _has_bits_[0] |= 0x00000010u;
}
inline void order::clear_has_date() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void order::clear_date() {
  date_ = 0;
  clear_has_date();
}
inline ::google::protobuf::int32 order::date() const {
  return date_;
}
inline void order::set_date(::google::protobuf::int32 value) {
  set_has_date();
  date_ = value;
}

// optional double begintm = 6 [default = 0];
inline bool order::has_begintm() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void order::set_has_begintm() {
  _has_bits_[0] |= 0x00000020u;
}
inline void order::clear_has_begintm() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void order::clear_begintm() {
  begintm_ = 0;
  clear_has_begintm();
}
inline double order::begintm() const {
  return begintm_;
}
inline void order::set_begintm(double value) {
  set_has_begintm();
  begintm_ = value;
}

// optional double endtm = 7 [default = 0];
inline bool order::has_endtm() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void order::set_has_endtm() {
  _has_bits_[0] |= 0x00000040u;
}
inline void order::clear_has_endtm() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void order::clear_endtm() {
  endtm_ = 0;
  clear_has_endtm();
}
inline double order::endtm() const {
  return endtm_;
}
inline void order::set_endtm(double value) {
  set_has_endtm();
  endtm_ = value;
}

// optional bool marketorder = 8 [default = false];
inline bool order::has_marketorder() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void order::set_has_marketorder() {
  _has_bits_[0] |= 0x00000080u;
}
inline void order::clear_has_marketorder() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void order::clear_marketorder() {
  marketorder_ = false;
  clear_has_marketorder();
}
inline bool order::marketorder() const {
  return marketorder_;
}
inline void order::set_marketorder(bool value) {
  set_has_marketorder();
  marketorder_ = value;
}

// -------------------------------------------------------------------

// orders

// repeated .TRANS_ORDER.order order_list = 1;
inline int orders::order_list_size() const {
  return order_list_.size();
}
inline void orders::clear_order_list() {
  order_list_.Clear();
}
inline const ::TRANS_ORDER::order& orders::order_list(int index) const {
  return order_list_.Get(index);
}
inline ::TRANS_ORDER::order* orders::mutable_order_list(int index) {
  return order_list_.Mutable(index);
}
inline ::TRANS_ORDER::order* orders::add_order_list() {
  return order_list_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::TRANS_ORDER::order >&
orders::order_list() const {
  return order_list_;
}
inline ::google::protobuf::RepeatedPtrField< ::TRANS_ORDER::order >*
orders::mutable_order_list() {
  return &order_list_;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace TRANS_ORDER

#ifndef SWIG
namespace google {
namespace protobuf {

template <>
inline const EnumDescriptor* GetEnumDescriptor< ::TRANS_ORDER::ebuysell>() {
  return ::TRANS_ORDER::ebuysell_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_order_2eproto__INCLUDED