//By waiwai@mszj 2000/12/02

inherit ITEM;
#include <ansi.h>
#include <task.h>
void create()
{
        set_name(HIR "�Ͻ��" NOR, ({"zijin kui", "kui"}));
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����Ѧ�ʹ���սɳ�������ı�����\n");
                set("unit", "��");
               set("owner_name","Ѧ�ʹ�");
               set("owner_id","xue rengui");
        }
}



