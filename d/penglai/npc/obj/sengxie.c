//Cracked by Roath
#include <armor.h>

inherit BOOTS;
void create()
{
        set_name( "ɮЬ", ({ "seng xie", "xie" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "˫");
		set("no_sell", 1);
                set("long", "һ˫Բ���಼ɮЬ����������Ь�ױ�һ��ɮЬ������࣬����Щ���߷첹�ĺۼ���");
                set("value", 100);
                set("material", "boots");
                set("armor_prop/armor", 3);
                set("armor_prop/dodge", 3);
        }
        setup();
}
void init()
{
        add_action("do_tear", "tear");
}

int do_tear(string arg){
        object ob,me;

        me=this_player();
        if( !this_object()->id(arg) ) return 0;
        ob=new("/d/penglai/npc/obj/ditu");
        ob->move(me);
	message_vision("$N����ɮЬʹ��һ������ž����һ����Ь�׼в��е�����СֽƬ��\n", me);
        destruct(this_object());
        return 1;
}

