//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
#include <task.h>
inherit ITEM;

void create()
{
        set_name("�ϹŶ�", ({"lao gudong", "gudong"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "��֪�µ��ϹŶ�\n");
                set("unit", "��");
               set("owner_name","��֪��");
               set("owner_id","He zhizhang");
        }
}


