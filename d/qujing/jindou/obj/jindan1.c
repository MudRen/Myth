// snowcat 4/25/97

#include <weapon.h>

inherit THROWING;

void self_dest()
{
    object env=environment(this_object());
    if(env)
        tell_object(env, name()+"�������ѿ�����绯ȥ�ˡ�\n");
    destruct(this_object());
}

void create()
{
  set_name("���ɰ��", ({"jindan sha", "sha"}));
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "һЩ��������Ľ�ɰ��\n");
    set("unit", "Щ");
    set("base_unit", "��");
    set("base_weight", 40);
    set("base_value", 1);
  }
  set("is_monitored",1);
  set_amount(18);
  set("rigidity",100);
  init_throwing(180);
  call_out("self_dest",600+random(600));
  setup();
}


