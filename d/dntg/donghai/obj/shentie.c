//sgzl

#include <ansi.h>

inherit F_UNIQUE;
inherit ITEM;


void create()
{
  set_name("����������", ({ "shen tie" ,"tie"}));
  set_weight(30000);
  set("long", @LONG
    
��˵�����������Ǵ�����ˮ֮ʱ��������ǳ���һ�����ӡ�
��ǰ��ϸ���ƣ� ԭ����ͷ�������𹿣��м���һ��������
���������Գɵ�һ���֣�����������𹿰�������һ����
ǧ��ٽ
LONG );

  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("material", "crimsonsteel");
    set("value", 20000000);
    set("no_get", "��ô�ֵ����������õ�������\n");
    set("no_sell", 1);
  }
  setup();
}

void init()
{
        add_action("do_xiao", "xiao");
}

int do_xiao()
{
  object me=this_object();
  object who=this_player();
  object ob;

  if (who->query("mana") < 500) 
     message_vision("$N���һ����С��С��С����ʲôҲû�з�����\n", who);
  else 
    {
     who->add("mana",-500); 
     if (random(5) < 4 )
        message_vision("$N���һ����С��С��С����\nֻ��������Ȼ��̱�ϸ��Щ��\n", who);
     else 
       {
       ob=new("/d/dntg/donghai/obj/jingubang");
       message_vision("$N���һ����С��С��С����\nֻ������������һ�������Ź�Ľ𹿰���\n", who);
       ob->move(environment(me));
       destruct (me);
       }
    }        
  return 1;
}

