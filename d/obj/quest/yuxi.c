//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <ansi.h>
#include <task.h>
void create()
{
        set_name(HIG"��������"NOR,({"yu xi"})); 
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long","���Ǵ��ƹ��ʵ���̫�ڵ�ӡ����������ˡ���۲�¡���ĸ�׭�֡�\n");
                set("unit", "��");
          set("owner_name", "��̫��");
          set("owner_id", "tang taizong");
        }
}

