// skills.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob;
        mapping skl, lrn, map;
        string *sname, *mapped;
        int i;

        seteuid(getuid());

        if(!arg)
                ob = me;
        else{
                ob = present(arg, environment(me));
//        if ( ob->query("SPSKILLS",1)  ) return ob->skills();           
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
                if (!ob) return notify_fail("��Ҫ�쿴˭�ļ��ܣ�\n");        }
        if( ob!=me && ob->query("env/invisibility")&&!wizardp(me) )
                return notify_fail("��Ҫ�쿴˭�ļ��ܣ�\n");

        if( ob!=me && !wizardp(me) 
        && !ob->is_apprentice_of(me) 
        && !me->is_apprentice_of(ob) 
        && getuid(ob)!=me->query("bonze/dadangid")
        && getuid(ob)!=me->query("couple/id"))
                return notify_fail("ֻ����ʦ����ʦͽ��ϵ�����ܲ쿴���˵ļ��ܡ�\n");

        skl = ob->query_skills();
        if(!sizeof(skl)) {
                write( (ob==me ? "��" : ob->name()) + "Ŀǰ��û��ѧ���κμ��ܡ�\n");
        
return 1;
        }
        write((ob==me ? "��" : ob->name()) +"Ŀǰ��ѧ��"+HIR+chinese_number(sizeof(skl))+NOR+"�ּ��ܣ�\n\n");
        
printf(NOR HIW"����������������������������"HIR"��  ��  ��  ��" HIW"����������������������������\n"NOR,);
        printf(NOR HIW"��"NOR YEL" ��ѧ����"NOR YEL" �� ����"NOR WHT"%-12s "NOR YEL" �Ա�"NOR WHT"%-10s "NOR YEL"I D��"NOR WHT"%-13s"NOR HIW"��\n"NOR,ob->name(),ob->query("gender"),"["+capitalize(ob->query("id"))+"]");
        printf(NOR HIW"�ǩ�������������������������������������������������������������������\n"NOR);
 sname  = sort_array( keys(skl), (: strcmp :) );        map = ob->query_skill_map();
        if( mapp(map) ) mapped = values(map);
        if( !mapped ) mapped = ({});

        lrn = ob->query_learned();
        if( !mapp(lrn) ) lrn = ([]);
        
        for(i=0; i<sizeof(skl); i++) {
printf(NOR HIW"��"NOR"%s%s%-40s" NOR "   - %-10s %4d/%5d"HIW"��"NOR"\n", 
                        (lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIR : "",
                        (member_array(sname[i], mapped)==-1? "  ": HIR"��"HIY),
                                      to_chinese(sname[i]) + " (" + sname[i] + ")",
                        SKILL_D(sname[i])->level_description(skl[sname[i]]),
                        skl[sname[i]], (int)lrn[sname[i]],
                );
 }
        
 printf(NOR HIW"��������������������������������������  "HIG"SJSH--CD"HIW"  ��������������������\n"NOR);
                        write("\n");
return 1;
}

int help(object me){
        write(@HELP
ָ���ʽ : skills|jineng [<ĳ��>]

���ָ����������ѯ��ѧ���ļ��ܡ�

��Ҳ����ָ��һ��������ʦͽ��ϵ�Ķ����� skills ���Բ�֪�Է��ļ���״����

��ʦ���Բ�ѯ�κ��˻� NPC �ļ���״����

HELP
    );
    return 1;
}

