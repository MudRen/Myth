//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
        set_name("ҩ��",({ "yaofang" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֽ");
                set("material", "paper");
                set("long", "����һ������ҽ��������ҩ����\n");
                set("owner_name", "��Ԩ����");
    set("owner_id", "wuyuan daozhang");
        }
}

// prescription.c

