//Cracked by Roath

// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
#include <ansi.h>
void create()
{
                set_name(HIR "����" NOR, ({"xiang nang" }));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                        set("long", "�ٻ�����ƽ���õ����ҡ�\n");
                      set("unit", "��");
                     set("owner_name","�ٻ�����");
                     set("owner_id","baihua xianzi");
        }
}


