//Cracked by Roath

// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
        set_name("�廨��", ({"xiuhua zhen", "zhen"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "佻�ƽʱ�������·��õ��롣\n");
                set("unit", "��");
               set("owner_name","佻�");
               set("owner_id","huan hua");
        }
}


