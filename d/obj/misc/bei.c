//create by guoth

#include <ansi.h>

inherit ITEM;

void create()
{
   set_name( HIG "��"+HIC+"��ʦ���"+HIG+"��" NOR , ({ "jinian bei" }) );
   set_weight(200000);
   set("long", @LONG
����Ϊ������Ե�Ĵ���Ӣ���������ļ��
���������ǵ����֣�

            ��: ��    �� (  cnd  )
            ��: ��Ϸ���� ( guoth )
            ��: һҶ֪�� ( vikee )
            ��: ��    �� (yudian )
            ��: �� �� �� ( caoji )
            ��: �� �� �� (greenwc)
            ��: ��    �� (hongdou)

         ϣ����Ҳ�ܳ�Ϊ������е�һԱ
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

