#include <ansi.h>
#include <armor.h>

//inherit S_RING;
inherit F_AUTOLOAD;
#include "/d/migong/box/gems/ring.c"

void create()
{
        set_name(HIG"Ǭ�����"NOR, ({ "magic ring", "ring" }));;
        set("long", HIC"����һ����Զ�����������Ľ�ָ���������һЩ��ֵ����\n"NOR);
        set("weight", 400);
        set("unit", "��");
        set("value", 5000000);
        set("material", "gem");
        set("armor_prop/armor", 10);
        set("armor_type", TYPE_FINGER);
        set("no_put",1);
        set("no_beg",1);
        set("no_steal",1);
        set("no_clone",1);
        set("no_pawn",1);
        set("no_beg",1);
        set("no_steal",1);
        setup();
}       

int query_autoload() { return 1; }

