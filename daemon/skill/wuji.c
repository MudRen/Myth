// wuji.c  ���޼��û���by cigar 2002.01

#include <ansi.h>

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return notify_fail("�޼��û�ֻ����ʦ��ѧ�����������ȡ�\n");
}
string exert_function_file(string func)
{
        return __DIR__"wuji/" + func;
}

int stage(int level)
{
             if ( level < 100 ) return 1;
        else if ( level < 180 ) return 2;
        else if ( level < 260 ) return 3;
        else if ( level < 340 ) return 4;
        else if ( level < 420 ) return 5;
        else if ( level < 560 ) return 6;
        else if ( level < 680 ) return 7;
        else if ( level < 800 ) return 8;
        else return 9;
}

string level_description(int level)
{
        if ( stage(level) < 3 )
                return BLU "��"+chinese_number( stage(level) )+"�Ρ�" NOR;
        else if ( stage(level) < 5 )
                return HIB "��"+chinese_number( stage(level) )+"�Ρ�" NOR;
        else if ( stage(level) < 7 )
                return YEL "��"+chinese_number( stage(level) )+"�Ρ�" NOR;
        else if ( stage(level) < 9 )
                return CYN "��"+chinese_number( stage(level) )+"�Ρ�" NOR;
        else 
                return HIW "��"+chinese_number( stage(level) )+"�Ρ�" NOR;
}

void skill_improved(object me)
{
        int level = (int)me->query_skill("wuji", 1);
        if ( stage(level) == stage(level-1) + 1)
        {
        if( (int)me->query("wuji_bonus") < stage(level) )
        {
        me->set("wuji_bonus", stage(level));
        me->set("max_kee", (int)me->query("max_kee") + stage(level)*100 );
        me->set("max_sen", (int)me->query("max_sen") + stage(level)*100 );
        me->save();
        log_file("wuji-bonus", ctime( time() )+": "
                                +me->query("name")+"("+me->query("id")+")"
                                +" got neili "+(stage(level)*100)+".\n");
                        message_vision(HIY "$NͻȻ�����������Σ����޼��û���ԭ����$N���޼��û������˵�"+chinese_number(stage(level))+"�ξ��磡\n" NOR, me);

                }
        }
                        
}
// passion addd
 string cast_spell_file(string spell) 
{
return CLASS_D("youning") + "/wuji/" + spell; 
}
