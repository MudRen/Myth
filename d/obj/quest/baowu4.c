//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
        set_name("������", ({"dinghai zhu","zhu"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�˱���춿��У�����ɫ���⣬��Ȼ���ɣ���֮������Ӧ֮������\n");
                set("unit", "��");
                set("lingtaibao","fake");
                set("owner_name","��Ԫ����");
                set("owner_id","zhenyuan daxian");
        }
}



