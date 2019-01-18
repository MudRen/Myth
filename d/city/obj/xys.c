// Update by waiwai@2003/04/25

inherit COMBINED_ITEM;
#include <ansi.h>

void create()
{
   set_name(HIM "������ңɢ" NOR, ({ "poison dust", "dust" }) );
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long",
        "����һ�ֶ������ҵĴ�ҩ������԰�����(pour)�ھ�ˮ֮��ʹ�á�\n" );
     set("unit", "Щ");
     set("base_unit", "��");
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
     return notify_fail("ָ���ʽ: pour <ҩ��> in <��Ʒ>\n");

   ob = present(what, this_player());
   if( !ob )
     return notify_fail("������û�� " + what + " ����������\n");
   if( !ob->query("liquid/remaining") )
     return notify_fail(ob->name() + "��ʲôҲû�У���װЩˮ�Ʋ����ܻ�ҩ�ۡ�\n");
   f = (: call_other, __FILE__, "drink_drug" :);
   ob->set("liquid/drink_func", bind(f, ob));
   ob->add("liquid/slumber_effect", 100);
   message_vision("$N��һЩ" + name() + "����" + ob->name() 
     + "��ҡ���˼��¡�\n", this_player());
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


