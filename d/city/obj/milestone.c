//Cracked by Roath
inherit ITEM;
#include <ansi.h>
int do_read(string arg);
void create()
{
      

        set_name(RED "��"HIG"�����μ��"RED"��" NOR, ({ "jinian bei","bei" }) );
        
        set("unit", "��");
        set("long", "����һ��������¼�����γ��������ʯ���������ŷ��������
������꣬���µ����ţ�ʯ�����ɡ����ϵ�����ȴ����
һ����һ����ʯ���Ͽ�¼�ţ�

             һ��"CYN"������ʮ��"YEL"����"NOR"
             ����"CYN"������ʮ��"YEL"���Ը���"NOR"
             ����"CYN"������ʮ��"HIR"P K ��ħ"NOR"
             �ģ�"CYN"������ʮ��"HIR"N K ����"NOR"
             �壺"CYN"������ʮ��"HIC"��ѧ����"NOR"
             ����"CYN"������ʮ��"RED"���и���"NOR"
             �ߣ�"CYN"������ʮ��"HIR"��������"NOR"
             �ˣ�"CYN"������"HIM"ʮ����Ů"NOR"    
             �ţ�"CYN"������ʮ��"GRN"��ǰ��"NOR"
             ʮ��"CYN"������ʮ��"GRN"TASK����"NOR"  
             
             
             
             
                                           
�������(read ���)���������ء�\n");       
        
        set("material","steel");
        set_weight(8888888);
        setup();
}

void init()
{
	add_action("do_read","read");
}

int do_read(string arg)
{
       string str;
	if(!arg||arg=="") 
	   return notify_fail("��Ҫ�Ķ���һ�����У�\n");
switch(arg)
	{
		case "һ": arg ="rich";break;
		case "��": arg = "quests";break;
		case "��": arg = "pker";break;
		case "��": arg = "nker";break;
		case "��": arg = "exp";break;
		case "��": arg = "dx";break;
		case "��": arg = "force";break;
		case "��": arg = "per";break;
		case "��": arg = "age";break;
		case "ʮ": arg = "task";break;		   
		default : arg = "none";break;
	}
	str="/adm/daemons/toptend"->topten_query(arg);
	write(str+"\n");

	return 1;
}