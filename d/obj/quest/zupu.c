//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
       set_name("�ڼ�������",({"zu pu"}));
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long","�����ڼ����ʼҵ����ס�\n");
                set("unit", "��");
          set("owner_name", "̫��");
          set("owner_id", "tai zi");
        }
}

