// bag by Calvin

inherit ITEM;

void create()
{
        set_name("����", ({ "bag" }) );
        set_weight(1000);
        set_max_encumbrance(100000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long", "����һֻ�ô�װ�����Ĳ���\n");
                set("value", 1000);
        }
}
int is_container() { return 1; }
