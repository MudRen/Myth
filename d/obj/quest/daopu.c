//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <ansi.h>
#include <task.h>
void create()
{
       set_name(HIB"��ͯ�´ȱ�������"NOR,({"dao pu"}));
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long","�����㽭۴����ͯ�����ž����ȱ����Ĳ�ȱ���ס�\n");
                set("unit", "��");
          set("owner_name", "�ȱ�����");
          set("owner_id", "cibei heshang");
        }
}
