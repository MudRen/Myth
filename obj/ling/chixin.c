// File: /obj/ling/chixin.c
// Written by Mudring@SanJie

#include <ansi.h>

inherit ITEM;
inherit PARTY;
inherit F_SAVE;

string query_autoload() { return "1"; }

void create()
{
    set_name(HIR "����Ů������" NOR, ({ "chixin ling", "ling" }));
    set_weight(10);
    if (clonep())
    set_default_object(__FILE__);
    else {
        set("long", @LONG
���ǳ���Ů����(chixin)�İ������ơ�
LONG );
        set("unit", "��");
        set("no_pawn", 1);
        set("no_sell", 1);
        set("no_copy", 1);
        set("item_make", 1);
        set("value", 1);
    }
}

string query_save_file()
{
    return DATA_DIR "ling/chixin";
}

