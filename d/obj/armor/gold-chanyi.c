//�����˿����   jinsi-chanyi.c
//by junhyun@SK

#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(HIY"��˿"HIW"����"NOR, ({ "jinsi-chanyi", "cloth" }) );
        set("long", "һ������ɽ�����³��Ľ�˿֯�ɵ����¡���\n");
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 50);
                set("armor_prop/spells", 10);
                set("armor_prop/dodge", 10);
                set("armor_prop/intelligence", 5);
                set("value", 200);
                set("no_sell", 1); // mudring.
                set("no_drop", 1); // mudring.
        }
        setup();
}

