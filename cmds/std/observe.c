// observe.c
// mon 1/4/97, msg_exp by crab.

#include <ansi.h>

int main(object me, string arg)
{
    string *msg_expression = ({
        "����¶������΢Ц��",
        "������һ�������ֻ���Ц��",
        "����¶����թ�����飬������뵽��ʲô�������ˡ�",
        "���ڱ��Ÿ�����ᡣ",
        "���Ŷ���Ц��ǰ����ϡ�",
        "üͷ��������֪����ʲô���¡�",
        "����������������˼״��",
        "ҧ���гݣ�һ���߷߲�ƽ�����ӡ�",
        "һ������ã����֪����Χ������ʲô�¡�",
        "����������ɵ�֡�",
        "��������״��",
        "�������Ʋ��֡�",
        "�����ذ���ͷ��������м�����顣",
        "ʹ����������죬�������ʹ��������",
        "��ǿ�ջ�Ц�������β�ס����İ��ˡ�",
        "����ü��ɫ�衣",
        "һ���������ࡣ",
        "����¶�����õ�Ц�ݡ�",
        "Ц�ñȿ޻��ѿ���",
        "��ǿ���Ų����Լ��޳�����",
        "������˿��",
        "����С������״��",
        "������Ц��¶������Ľ�����",
});

     int size=sizeof(msg_expression);
     int spellme,spellwho,know;
     object who;
     string str;

     if (!arg || !objectp(who=present(arg,environment(me))) ||
	 !living(who))
	 return notify_fail("����鿴˭��\n");
     if (who==me) return notify_fail("�����Լ���\n");
     
     if (me->query("mana")<100)
	 return notify_fail("��ķ������㡣\n");
     me->add("mana",-50);

     spellme=me->query_skill("spells");
     spellwho=who->query_skill("spells");

     if (random(20)<((spellme-spellwho)/10+10) && 
	 who->name()!=who->query("name") &&
	 who->query_temp("d_mana")>0) {
       str="ȴ��"+who->query("name");
       know=1;
     }
     else {
       str="ֻ��"+who->name();
       know=0;
     }

     if (random(3)==1)
       tell_object(who, "��һ̧ͷ������"+me->name()+
         "����һ��������Ŀ������Ͷ����\n");
     write("��΢һ������"+who->name()+"ϸϸ������ȥ��"
       +str+msg_expression[random(size)]+"\n\n");
    
     if(know==1&&who->query_temp("d_mana")>0) {
       write("\n��Ҫ���÷�����ʹ"+who->name()+
         "�ֳ�������(y/n)[n]");
       input_to("do_force",me,who);
     }

     return 1;
}
	 
void do_force(string yn,object me,object who)
{    
     if(!objectp(present(who,environment(me)))) {
       write("���Ŀ���Ѿ������ˡ�\n");
       return;
     }

     if( yn[0]=='y' || yn[0]=='Y' ) {
       if(me->query("mana")<=100) {
         write("�����ڵķ���̫���ˡ�\n");
	 return;
       } else {
         me->add("mana",-100);
         message_vision("$N��$n���һ����"+RANK_D->query_rude(who)+
         "������ԭ�Σ�\n",me,who);
         if(random(2)==0&&who->query_temp("d_mana")>0) {
	   int mana=who->query("mana");
	     
	   mana-=200;
	   if(mana<0) mana=0;
	   who->set("mana", mana);

           message_vision("ֻ��$N"+
           "��������̱���ڵأ�����ȴ��Ȼ����"+who->query("name")+"��\n",who);
            who->delete_temp("spellslevel");
            who->delete_temp("d_mana");
            who->delete_temp("apply/name");
            who->delete_temp("apply/id");
            who->delete_temp("apply/short");
            who->delete_temp("apply/long"); 
	    who->delete_temp("no_heal_up/bian");
         }
     }
   }
   return;
}

int help(object me)
{
      write(@HELP

ָ���ʽ �� observe <����> ��
	    observe <����> [ 2 | 3 | ...] ���ж��ͬ������ʱ��

���ָ���������÷������۲�����������ķ�����ǿ����
����ʶ�Ʊ��˵ı�������

�������ָ� bian
HELP
     );
     return 1;
}


