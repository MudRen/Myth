//create by guoth

#include <ansi.h>

inherit ITEM;

void create()
{
   set_name( HIW "��ԯ��Ĺ����ʯ��" NOR , ({ "geshi bei","bei" }) );
   set_weight(200000);
   set("long", @LONG
            ���Ĺ�� �����赨����ϸ Ů��Ҫ�����绪
        �޸�֮�� ����ѧ�ĺ��书 ��ò֮�� ����ѧ�ú÷���
               ���ҹ�Ĺ����̵ü�į���ܷ�ͼǿ��
               �г�һ�����ҹ�Ĺ��չ����������֮��
LONG);
       if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "stone");
                set("value", 2000);
                set("no_get", 1);
                set("amount",30);
        }
 
            setup();
}


