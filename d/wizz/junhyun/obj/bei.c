//������Ӣ�ۼ��
//by junhyun@SK

#include <ansi.h>

inherit ITEM;

void create()
{
   set_name( HIW "��������" NOR , ({ "jinian bei","bei" }) );
   set_weight(200000);
   set("long", @LONG

����Ӣ�ۼ�� ����������ſ�����������ǵ����֣�

               �������(helpler)��
               ���    ��(mudring)��
               �    ��( cigar )��
               �    ��( koker )��
               �    ��( sklll )��

ϣ����Ҳ�ܳ�Ϊ�������һԱ�����Ŭ��Ŷ
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


