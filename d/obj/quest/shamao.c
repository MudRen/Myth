//Cracked by Roath

// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
        set_name("ɵñ", ({"sha mao", "cap"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "���Ľ���ϲ������ñ�ӡ�\n");
                set("unit", "��");
               set("owner_name","���Ľ���");
               set("owner_id","yingwu jiangjun");
        }
}


