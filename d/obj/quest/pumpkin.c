//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */

inherit ITEM;
#include <task.h>
void create()
{
        set_name("�Ϲ�", ({ "pumpkin" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��ԲԲ�ģ�Ӳ���Ĵ��Ϲ�\n");
                set("unit", "��");
                set("value", 15);
                set("owner_name","�๫");
                 set("owner_id","xiang gong");
        }
}

