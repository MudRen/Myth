//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
       set_name("����",({"zhu lan"}));
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long","��������Ů��ժ����õ������ӡ�\n");
                set("unit", "��");
          set("owner_name", "������Ů");
            set("owner_id", "suyi xiannu");
        }
}

