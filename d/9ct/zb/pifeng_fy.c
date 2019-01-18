//飞羽披风 by koker
#include <ansi.h>
#include <armor.h>

inherit SURCOAT;
int do_wear(string arg);
void create()
{
  set_name(HIC"飞羽披风"NOR, ({"feiyu pifeng"}));
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "相传这件亮色的披风是精华台出的宝物。\n");
    set("material", "leather");
    set("unit", "件");
             set("value", 12000);
    set("armor_prop/armor", 20);
    set("armor_prop/spells", 10);//装备等级是1-10的，此处是5；11-20的，此处是10
    set ("armor_prop/force", 10);//20以上等级的装备可以是15-50
    set("armor_prop/parry", 20);
    set("level",50);
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
  
     if(who->query("level") <50)
{
   message_vision("$n需要等级是50级以上的玩家才能佩带，$N还是先去升级你的等级吧。\n",who,me); 
   return 1;
}
   return 0;
}
