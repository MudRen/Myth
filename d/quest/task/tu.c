//By waiwai@mszj 2000/12/02
//yngw ����Ż� 2001/02/09
#include <ansi.h>
inherit ITEM;
#define TASK_D    __DIR__"questd"

int do_locate(string arg);
int do_task();

void create()
{
        set_name(HIW"̽��"HIG"ͼ"NOR, ({"tanbao tu","tu"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long", "����һ������Ѱ�Ҷ�ʧ�����̽��ͼ��\n"+
                        "����(location)�����ҵ���Ʒ�Ĵ��λ�ã�\n");
                set("unit", "��");
                  set("value", 0);
        }
}


void init()
{
  add_action("do_locate","location");
  add_action("do_task","task");
}

int do_task()
{
   string output;
   object me = this_player();

   me->add("sen",-20); 

   output="̽��ͼ��ͻȻӳ�ֳ�һƪӬͷС�֣�\n\n";
   output += HIR"�� "HIW"��������������"HIR" ��"HIG" ʹ����\n" NOR; 
   output += ""HIW"��������������������������������������������������������������������������\n"NOR"";   
   output += TASK_D->dyn_quest_list();  
   output += ""HIW"��������������������������������������������������������"HIG"��������������"HIW" ��������\n\n"NOR""; 

   me->start_more(output);
   return 1;
}


//  int query_autoload() { return 1; }

int do_locate(string arg)
{
   if ( ! arg)

   return notify_fail("location <��Ʒid>\n");
   else
   TASK_D->locate_quest(this_player(),arg);
   return 1;
}


