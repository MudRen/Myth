
#include <ansi.h>
inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
        object weapon;
        
        string *w_num,id;
        mapping skl;     
        
                w_num=({"weapon1","weapon2","weapon3","weapon4","weapon5",
                "weapon6","weapon7","weapon8","weapon9","weapon10",});
        
        if (me->is_busy())  
                return notify_fail("��æ����������������������ɣ�\n");  
        if (!me->query("new_weapons"))
          return notify_fail("������û�б�ʯ��������\n");
         
        if (!arg && member_array(arg,w_num)==-1)
                          return notify_fail("���л�ʲô����\n");
         id = me->query("id");
         skl=WSAVE_D->query_my_weapon(id); 
        if(undefinedp(skl[arg]))
          return notify_fail("�����ڻ�û��������������\n");
        
       weapon= WSAVE_D->get_weapon(id,arg);
                  if (environment(weapon)==me)
                     return notify_fail("��������������?\n");
         
                 
//         if (weapon->query("equipped"))  weapon->unwield();
         if (weapon->query("equipped")) {
           if( environment(weapon) && environment(weapon)->is_character()) weapon->unequip();
               else weapon->delete("equipped");
                                     }
             weapon->set("no_sell",1);
        if (weapon->move(me))
        {
        message_vision(HIY"\n    ֻ�������һ��������$n"HIY"�������,����$N�Ļ��С�\n\n"NOR,me,weapon);
        }else 
        {
        destruct(weapon);
        
        return notify_fail("�ٻ�ʧ�ܣ�\n"); 
        }

        me->start_busy(3);
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ�� zhaohui

���ָ����������ٻ���ı�ʯ����������
HELP
 );
        return 1;
}

