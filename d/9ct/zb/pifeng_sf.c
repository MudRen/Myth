//�������� by koker
#include <ansi.h>
#include <armor.h>

inherit SURCOAT;
int do_wear(string arg);
void create()
{
  set_name(HIY"�������"NOR, ({"shenfeng pifeng", "pifeng"}));
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "�ഫ�����ɫ�������Ǿ���̨���ı��\n");
    set("material", "leather");
    set("unit", "��");
             set("value", 12000);
    set("armor_prop/armor", 10);
    set("armor_prop/spells", 5);//װ���ȼ���1-10�ģ��˴���5��11-20�ģ��˴���10
    set ("armor_prop/force", 5);//20���ϵȼ���װ��������15-50
    set("armor_prop/parry", 10);
    set("level",10);
  }
  setup();
}

int init()
{
        add_action("do_wear","wear");
        return 1;
}

int do_wear (string arg)
{
   object me=this_object(),who=this_player();
  
     if(who->query("level") <20)
{
   message_vision("$n��Ҫ�ȼ���20�����ϵ���Ҳ��������$N������ȥ������ĵȼ��ɡ�\n",who,me); 
   return 1;
}
   return 0;
}
