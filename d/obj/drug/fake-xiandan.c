//���ɵ�


#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_give","��ô����ҩ�����������ˣ�\n");
    set("no_drop","��ô����ĵ�ҩ�����˶��ϧѽ��\n");
    set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
  }                                    
    add_action("do_eat", "eat");
}

void create()
{
  set_name(HIW "�ɵ�" NOR, ({"xian dan","dan"}));
  set_weight(200);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "ö");
    set("long", "һö���ɫ�ĵ�ҩ�����������ĵĻƹ⡣\n");
    set("drug_type","��Ʒ");
  }
  
  // the following line is added by snowcat
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  if (!id(arg))
    return notify_fail("��Ҫ��ʲô��\n");
  
    message_vision(HIG "$N���ɵ��������ʵ����У���ɫͻȻת�̣�һ�µ����ڵأ�\n" NOR, me);
    tell_object(me,BLK "�㸹����ͬ����һ�����ܣ�ʹ�����ڵ���ֱ�����\n\n" NOR);

    this_player()->unconcious();

  destruct(this_object());
  return 1;
}

