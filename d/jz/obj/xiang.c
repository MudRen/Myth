//Cracked by Roath

inherit ITEM;

void create()
{
        set_name("[33m������[m", ({ "xiang","box" }) );
        set_weight(500);
        set_max_encumbrance(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("no_get",1);
                set("long", "����һ�ڽ���ļ������ӡ�\n");
                set("value",900);
        }
}

int is_container() { return 1; }
