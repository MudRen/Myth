#include <ansi.h> 
#include <localtime.h> 
#define REMON 8  // �·ݣ�ʵ���·ݵ���������ּ�1 
#define REDAY 15 // ���� ��20��24Ϊֹ 
#define REEXP 120000 // ���һ�㽱����С��Ҫ��exp 
inherit ITEM; 

string *GetName = ({ 
        "��ɳ�±�", 
        "�����±�", 
        "Ҭ���±�", 
        "�����±�", 
        "֥���±�", 
        "���±�", 
        "���±�", 
        "��Ƥ�±�", 
        "�����±�", 
        "��ζ�±�", 
        "�����±�", 
        "Ҭ���±�", 
        "�������±�", 
        "�����±�", 
        "�����±�", 
        "�����±�", 
        "�ٹ��±�",
        "ˮ���±�",
}); 

varargs string GetColor(int flag) 
{ 
        string color; 
        if (flag) 
                color = COLOR_D->random_color(4); 
        else { 
                if (random(2)) 
                        color = COLOR_D->random_color(4); 
                else 
                        color = COLOR_D->random_color(3); 
        } 
        return color; 
} 

string SetName() 
{ 
        int i = random(sizeof(GetName)); 
        return (GetColor() + GetName[i] + NOR); 
} 


void create() 
{ 
        string myName; 
        myName=SetName(); 
        set_name( myName, ({ "cake"}) ); 
        set("long","һ��СС��" + myName + "��������ģ��ճ�¯�������ȵ��أ�\n"+
                   "�����ʽeat cake (0-4)��\n"
                   "0�����н��� 1��Ǳ�ܽ��� 2����ѧ���� 3����ʯ����  4���ƽ�����");
 
        set_weight(50); // һ�� 
        if( clonep() )  
                set_default_object(__FILE__); 
        else { 
                set("unit", "��"); 
                set("value", 5000); // 50 silver one 
                set("no_sell","�������ˣ��±�ҲҪ����\n"); 
                set("no_get","���±��ԣ�\n"); 
                set("no_put","���ղذ���\n"); 
                set("no_drop","�ٺ�......��\n"); 
                set("no_give","�Լ����Űɣ�\n"); 
        } 
        set("is_monitored",1); 
        setup(); 
}

void init()
{
    if (!wizardp(this_player())) {
        set("no_get"," �ٺ٣����ΰ�! \n");
        set("no_drop","��ô����Ķ�������������! \n");
        set("no_give","��̫�����˰ɣ�\n");
        set("no_put","��������ˣ�\n");
        set("no_sell","��ô����Ķ�����������������ģ�\n");
       }
        add_action("do_eat", "eat");
       

}

int do_eat(string arg)

{
        object me,newob;
        int exper,dx,tt1,tt2,qn,i,improve=0;

        me = this_player();


        if (!arg)
        return notify_fail("��Ҫ��ʲô��\n");

        if ( this_object()->query("owner") != me->query("id"))
        {
           message_vision(HIR"\n͵���±����������Ρ�\n"NOR,me);
           me->move("/d/wiz/jail");
           return 1;
        }
      
        
       switch(arg){
        case "cake 0":
               dx= me->query("daoxing");
               tt2= dx/60+random(dx/100)+300;
               if(tt2 > 100000) tt2=100000;
               message_vision(HIY"$n��$N������ϲ��ϲ�����õ����������ˡ�\n"NOR,me,this_object());
               me->set("daoxing",dx + tt2);
               message_vision(HIY+me->name()+"�ĵ��д���"+tt2+"�㡣��\n"NOR,me);
               break;
        case "cake 1":
               qn= me->query("potential");
               if( (int)me->query("potential") > (int)me->query("learned_points"))
                        qn=(int)me->query("potential")-(int)me->query("learned_points");
               tt1= qn/60+random(qn/100)+60;
               me->add("potential",tt1);
               message_vision(HIY"$n��$N������ϲ��ϲ�����õ����������ˡ�\n"NOR,me,this_object());
               message_vision(HIY+me->name()+"��Ǳ�ܴ���"+tt1+"�㡣��\n"NOR,me);
               break;
       case "cake 2":
               exper = me->query("combat_exp");
               improve=exper/50+random(exper/30)+3000;
               if(improve > 100000) improve=100000;
               message_vision(HIY"$n��$N������ϲ��ϲ�����õ����������ˡ�\n"NOR,me,this_object());
               me->set("combat_exp",exper+improve);
               message_vision(HIY+me->name()+"����ѧ����"+improve+"�㡣��\n"NOR,me);
               break;
        case "cake 3":
                for(i=0;i<3;i++)
                {
                        
                newob=new("/d/quest/baoshi/baoshi");
                newob->move(me);
                }
                message_vision(HIY"$n��$N������ϲ��ϲ�����õ����������ˡ�\n"NOR,me,this_object());
                message_vision(HIY+me->name()+"�ȵ����ɸ���ʯ������\n"NOR,me);
                break;
        case "cake 4":
                newob=new("/obj/money/gold");
                improve=(me->query("daoxing"))/10000+1;
                if(improve > 518) improve=518;
                newob->set_amount(improve);
                newob->move(me);
                message_vision(HIY"$n��$N������ϲ��ϲ�����õ����������ˡ�\n"NOR,me,this_object());
                message_vision(HIY+me->name()+"�ȵ�"+improve+"���ƽ𣡡���\n"NOR,me);
                break;
       default :
                tell_object(me,"�����ʽeat cake (0-4)��\n");
                return 1;
        }               
        if( random(400) < 2)
          {
           message_vision(HIY"��ϲ����,"+me->name()+"����ͷ������\n"NOR,me);
/*
           switch(random(5)){
              case 0:
              me->add("str",1);
              message_vision(HIY+me->name()+"��������һ�㡣��\n"NOR,me);
              me->add("cor",1);
              message_vision(HIY+me->name()+"�ĵ�ʶ��������һ�㡣\n"NOR,me);
              break;
              case 1:
              me->add("per",1);
              message_vision(HIY+me->name()+"����ò��Ư����һ�㡣\n"NOR,me);
              me->add("cor",1);
              message_vision(HIY+me->name()+"�ĵ�ʶ��������һ�㡣\n"NOR,me);
              break;
              case 2:
              me->add("cor",1);
              message_vision(HIY+me->name()+"�ĵ�ʶ��������һ�㡣\n"NOR,me);
              me->add("cps",1);
              message_vision(HIY+me->name()+"�Ķ�����������һ�㡣\n"NOR,me);
              break;
              case 3:
              me->add("cps",1);
              message_vision(HIY+me->name()+"�Ķ�����������һ�㡣\n"NOR,me);
              me->add("str",1);
              message_vision(HIY+me->name()+"��������һ�㡣��\n"NOR,me);
              break;
              case 4:
              me->add("cps",1);
              message_vision(HIY+me->name()+"�Ķ�����������һ�㡣\n"NOR,me);
              me->add("per",1);
              message_vision(HIY+me->name()+"����ò��Ư����һ�㡣\n"NOR,me);
              break;
                }
*/
                me->add("balance",30000000);
                message_vision(HIY+me->name()+"�Ĵ��������3000���ƽ�\n"NOR,me);
             }
       else {
             message_vision(HIY"��ϲ����,"+me->name()+"û����ͷ��,��ϧѽ,�´������ɡ���\n"NOR,me);

           }
        destruct(this_object());
        return 1;


}


