//δ�����˿����   jinsi-chanyi.c
//by junhyun@SK

#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(HIC"��˿"HIW"����"NOR, ({ "jinsi-chanyi", "cloth" }) );
        set("long", "һ������ɽ�����³��Ľ�˿֯�ɵ����¡���\n");
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 15);
                set("armor_prop/spells", 3);
                set("armor_prop/dodge", 3);
                set("armor_prop/intelligence", 10);
                set("value", 200);
        }
        setup();
}

