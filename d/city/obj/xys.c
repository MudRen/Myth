// Update by waiwai@2003/04/25

inherit COMBINED_ITEM;
#include <ansi.h>

void create()
{
   set_name(HIM "极乐逍遥散" NOR, ({ "poison dust", "dust" }) );
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long",
        "这是一种毒性猛烈的春药，你可以把它倒(pour)在酒水之中使用。\n" );
     set("unit", "些");
     set("base_unit", "包");
     set("value", 50000);
     set("base_value", 50000);
    set("food_remaining", 1);
    set("food_supply", 0);

     set("weight", 90);
    set("material", "food");

   }
   set_amount(1);
}

void init()
{
	if( this_player()==environment() )
	add_action("do_pour", "pour");
}

int do_pour(string arg)
{
   string me, what;
   object ob;
   function f;

   if( !arg
   ||   sscanf(arg, "%s in %s", me, what)!=2
   ||   !id(me) )
     return notify_fail("指令格式: pour <药粉> in <物品>\n");

   ob = present(what, this_player());
   if( !ob )
     return notify_fail("你身上没有 " + what + " 这样东西。\n");
   if( !ob->query("liquid/remaining") )
     return notify_fail(ob->name() + "里什么也没有，先装些水酒才能溶化药粉。\n");
   f = (: call_other, __FILE__, "drink_drug" :);
   ob->set("liquid/drink_func", bind(f, ob));
   ob->add("liquid/slumber_effect", 100);
   message_vision("$N将一些" + name() + "倒进" + ob->name() 
     + "，摇晃了几下。\n", this_player());
   add_amount(-1);
   return 1;
}

int drink_drug(object ob)
{
   this_player()->apply_condition("slumber_drug",
     (int)this_player()->query_condition("slumber_drug") 
     + (int)ob->query("liquid/slumber_effect") );
   return 0;
}


