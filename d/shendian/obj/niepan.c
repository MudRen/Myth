
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("�������", ({"niepan", "pan"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",HIR"һ����ɫ��Բ�̡�������Ž�ľˮ�������ַ��šNNOR�");
                set("base_unit", "��");
                set("base_weight", 0);
                set("no_sell","��ô���Ķ�������ɲ����գ�" );
                set("no_get","�������������");
                set("no_give","��ô���Ķ��������˲���ð�"); 
        }
         setup();
}

