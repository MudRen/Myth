// ��¥��
// created 7/7/1997 snowcat

inherit ITEM;
#include <ansi.h>

string name = "����¥�Ρ���ʮ�˻�";
string number = "018";

void init();

int do_read();
void create()
{
  set_name(name, ({"hlm", "book"}));
  set_weight(200);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", " Ǭ¡������إ�غ�¥�θ�У���� "+name+" ���� read �Ķ���");
    set("material", "paper");
  }
}

void init()
{
  add_action("read_book", "read");
}

int read_book(string arg)
{
  object me = this_player();
  object ob = this_object();
    
  if (!ob->id(arg))
      return notify_fail("��Ҫ��ʲô��\n");
  write("\n");
  me->start_more(read_file("/d/obj/books-nonskill/text/hmeng"+number));
  write("\n");
  return 1;
}

