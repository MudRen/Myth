#include <ansi.h>
inherit ITEM;
void create()
{
        set_name( "������" , ({"zangpanzi"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("task_give", 1);
                set("deadfly", 1);
                set("no_get", 1);
                set("long", "һ���ո��ù��������ӡ�\n");
        }
        setup();
}
