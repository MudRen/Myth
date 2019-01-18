// updatei.c
// by Doing

#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        string file;
        string *opts;
        int opt_compile;
        int opt_detail;
        int opt_force;

        object env;
        object ob;
        object *obs;
        string *base;
        string *temp;
        int i;
        int k;
        int level;
        int count;

        if (! SECURITY_D->valid_grant(me, "(admin)"))
                return 0;

        seteuid(geteuid(me));

        if (! arg)
                return notify_fail("�����ָ����༭�ļ̳еĸ�����·������\n");

        file = 0;
        opt_compile = 0;
        opt_detail = 0;
        opt_force = 0;
        opts = explode(arg, " ");
        for (i = 0; i < sizeof(opts); i++)
        {
                switch(opts[i])
                {
                case "-c":
                        opt_compile = 1;
                        break;

                case "-d":
                        opt_detail = 1;
                        break;

                case "-f":
                        opt_force = 1;
                        break;

                default:
                        file = resolve_path(me->query("cwd"), opts[i]);
                }
        }

        if (! sscanf(file, "%*s.c")) file += ".c"; 
        if (file_size(file) < 0)
                return notify_fail("û�� " + file + " ���������\n");
        me->set("cwf", file);

        obs = filter_array(objects(), (: inherits($(file), $1) &&
                                         ! userp($1) &&
                                         ! playerp($1) &&
                                         ! clonep($1) :));
// 71          obs -= ({ find_object(VOID_OB), find_object(TEMP_OB) });
        obs -= ({ find_object(VOID_OB) });
        if (sizeof(obs) > 1024 && ! opt_force)
        {
                write("һ���� " + sizeof(obs) + " �����ǣ��"
                      "���ڣ������������룬��ָ��-f������\n");
        }

        if (sizeof(obs) > 100 && opt_compile)
                message_system("���±������м̳е��������Ժ�...");

        base = ({ file });
        count = 0;
        level = 0;

        while (sizeof(base))
        {
                if (! level)
                        write(HIG "������ļ���" + file + "���ܹ� " +
                              sizeof(obs) + " ���̳��ļ���\n" NOR);
                else
                        write(sprintf(WHT "����� %d �μ̳е� %d ��"
                                      "�ļ�����ʣ %d ���ļ���\n" NOR,
                                      level, sizeof(base), sizeof(obs)));
                temp = ({ });
                for (i = 0; i < sizeof(base); i++)
                {
                        reset_eval_cost();
                        if (opt_compile)
                        {
                                object *moves;

                                if (opt_detail) write("����" + base[i] + ":");

                                moves = 0;
                                if (ob = find_object(base[i]))
                                {
                                        // if a player in this room, I should move all
                                        // the objects out.
                                        if (sizeof(filter_array(deep_inventory(ob),
                                                                (: userp($1) || playerp($1) :))) > 0)
                                        {
                                                moves = all_inventory(ob);
                                                moves->move(VOID_OB, 1);
                                        }
                                        env = environment(ob);
                                        destruct(ob);
                                } else
                                {
                                        // no object, so no environment
                                        env = 0;
                                }
                
                                if (catch(ob = load_object(base[i])))
                                {
                                        write(HIR "\n��������������ֹ��\n" NOR);
                                        return 1;
                                }

                                // compiled successfully, I should move the
                                // objects in void back, if I has been move them
                                // out from old object.
                                if (objectp(ob) && arrayp(moves))
                                        moves->move(ob, 1);

                                if (opt_detail) write("�ɹ���\n");

                                // if the old object has environment, I should
                                // replace this object in the environment.
                                if (environment(ob) != env && env)
                                        ob->move(env);
                        } else
                        {
                                if (opt_detail)
                                        write("��Ҫ����" + base[i] + "��\n");
                        }
                        count++;
        
                        for (k = 0; k < sizeof(obs); k++)
                        {
                                if (member_array(base[i], inherit_list(obs[k])) != -1)
                                {
                                        temp += ({ base_name(obs[k]) + ".c" });
                                        obs[k] = 0;
                                }
                        }
                        obs -= ({ 0 });
                }

                level++;
                base = temp;
        }

        if (count > 0)
                write(HIC "�ܹ���" + HIW + count + HIC "������" +
                      (opt_compile ? "���ɹ����룡\n" NOR : "��Ҫ���롣\n" NOR));
        else
                write(HIC "û�б����κε�����Ҫ���롣\n" NOR);

        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : updatei <������> [-c] [-d] [-f]
 
���ָ����Ը���ĳ�����������м̳иõ����������������Щ����
���������������¡������������/feature/message����̳и���
����/inherit/char/char�ͼ�Ӽ̳е�/inherit/char/npc ���ᱻ��
�±��롣���һ���������Ҷ����򲻻ᱻ���롣

�����ָ������-c����ϵͳֻ���г���Ҫ������Щ���������ָ����
����-d���������ϸģʽ�г�������Ҫ����ĵ��������ָ����-f��
�������ж��󣬷��򳬹���1024���ļ�ϵͳ�Ͳ�����б��롣
HELP );
    return 1;
}

