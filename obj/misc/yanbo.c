// yanbo.c �в�

inherit ITEM;

void create()
{
        set_name("�в�", ({ "yanbo", "bo" }));
        set_weight(600);
        set_max_encumbrance(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long", "һֻ�����Ĵ��룬��������ĥҩ��\n");
                set("value", 200);
        }
}

int is_container() { return 1; }

int can_make_medicine() { return 1; }
