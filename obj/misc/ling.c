// /obj/misc/ling.c
// Written by Mudring@SanJie

#include <ansi.h>

inherit ITEM;
inherit PARTY;

string query_autoload() { return "1"; }

void create()
{
    set_name(HIR "�������" NOR, ({ "party ling", "ling" }));
    set_weight(10);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", @LONG
����һֻ�������ƣ��������Ű��ɵ�Ȩ����������
LONG );
        set("unit", "��");
        set("no_pawn", 1);
        set("no_sell", 1);
        set("no_copy", 1);
        set("item_make", 1);
        set("value", 1);
    }
}