inherit ITEM;

#include <ansi.h>

void create() {
  set_name("����",({"pi wen","piwen","wen"}));
  set_weight(10);
  set("unit","��");
  setup();
}
void init() {
  add_action("do_look","look");
}

int do_look(string arg) {
  object me=this_player();

  if (arg!="pi wen" && arg!="piwen" && arg!="wen") return 0;
  write(this_object()->long());
  if (query("target")!=me->query("name")) return 1;
  message_vision(HIR"$N�������ģ���Ȼ��ŭ��������˺�˸����飬��У�������ȥ���������������\n"NOR,me);
  destruct(this_object());
  return 1;
}
