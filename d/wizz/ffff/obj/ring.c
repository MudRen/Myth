#include <ansi.h>
inherit F_UNIQUE;
#include <armor.h>

inherit FINGER;

void create()
{
        set_name(RED"ħ"+YEL"��"NOR, ({ "mo jie", "jie", "ring" }));
        set("weight", 10); 
        set("long",HIM"����һöע�����������������������"+HIR"�ǡ�ѩ"+HIM"2���֡�\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ö"); 
                set("no_drop", "��ô�ѵõĽ�ָ�������Űɡ�\n"); 
                set("no_give","��ô�ţ����ʲô���㣿����\n"); 
                set("no_get","���ˣ�С������ɱ���㰡��\n");
                set("value", 100000);
                set("material", "gold");
                set("no_sell", 1);
                set("monitord", 1);
       if(!wizardp(this_player())) set("no_give", 1);
                set("armor_prop/armor", 20);
                set("armor_prop/intelligence", 15);
                set("armor_prop/personality", 25);
        }
        setup();
}

int query_autoload() { return 1; }


