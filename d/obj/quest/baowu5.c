//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
        set_name("���Լ�", ({"jinjiao jian","jian"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�˼�������������������������������¾��������ڿ��У��������£�\n���ƻ��壬ͷ��ͷ�����β��β��ɣ�������õ����ɣ�һ�����Ρ�\n");
                set("unit", "��");
                set("lingtaibao","fake");
                 set("owner_name","������ʦ");
                 set("owner_id","master puti");
        }
}



