#include <ansi.h>
#include <dbase.h>
#include <armor.h> 
inherit F_AUTOLOAD;

inherit FINGER;

void create()
{
  set_name(HIB "草原の光" NOR, ({ "caoyuan yueguang"}));
  set("weight", 100); 
    set("long",HIR"新婚戒指,阿修送给美丽清纯的瞳瞳的结婚戒指，它代表阿修的一片真心爱小颖永不变！
\n"NOR);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "个"); 
    set("no_drop", "老公阿修送的啊，丢弃了你心里好受嘛？。\n");  
    set("no_steal", "老公阿修送的啊，别丢好吗？。\n"); 
    set("no_put", "老公送的啊，以后没了难道你心里也没了他吗？。\n"); 
    set("no_get", "老公送的啊，别get好吗？。\n");
    set("value", 1000000000);
    set("material", "gold");
    set("armor_prop/armor", 1);
  }
  setup();
}

int query_autoload() { return 1; }
