//Cracked by Roath

// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
              set_name("�ƴ�", ({"jiudai" }));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                      set("long", "Ԫ�����Ⱦ��õĶ�����\n");
                      set("unit", "��");
                   set("owner_name","Ԫ����");
                   set("owner_id","yuan xiansheng");
        }
}


