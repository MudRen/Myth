// name.c
// modify by mudring

#include <ansi.h>
#include <dbase.h>
#include <condition.h>

static string *my_id;

string *query_my_id()
{
    return my_id;
}

void set_name(string name, string *id)
{
    set("name", name);
    set("id", id[0]);
    my_id = id;
}

int id(string str)
{
    string *applied_id;

    if (this_player() && !this_player()->visible(this_object())) return 0;

    if (pointerp(applied_id = query_temp("apply/id")) && sizeof(applied_id))
        if (member_array(str, applied_id)!=-1)
            return 1;
        else
            return 0;
    
    if (pointerp(my_id) && member_array(str, my_id)!=-1)
        return 1;
    else
        return 0;
}

string *parse_command_id_list()
{
    string *applied_id;

    if (pointerp(applied_id = query_temp("apply/id")) && sizeof(applied_id))
        return applied_id;
    else
        return my_id;
}

varargs string name(int raw)
{
    object me = this_object();
    string str, *mask;
        
    if (!raw && sizeof(mask = query_temp("apply/name")))
         return mask[sizeof(mask)-1];
    if (! raw && wizardp(me)
        && intp(query("env/invisibility"))
        && query("env/invisibility") > 6)
        return "ĳ��";
    if (stringp(str = query("name")))
        return str;

    return file_name(me);
}

// rewritten for sjsh lib
// mudring Oct/13/2002
varargs string short(int raw)
{
    string title, nick, str, *mask;
    string force;
    mapping msg;
   
    object me = this_object();

    if (!stringp(str = query("short")))
    {
        if (query("color"))
            str = query("color") + name(raw) + NOR "(" + capitalize(query("id")) + ")";
        else
            str = name(raw) + "(" + capitalize(query("id")) + ")";
    }

    if (!me->is_character()) return str;

    if (!raw && sizeof(mask = query_temp("apply/short")))
        str = (string)mask[sizeof(mask)-1];
    else
    {
        if (stringp(nick = query("nickname")))
            str = sprintf("��%s��%s", nick, str);

        title = me->query("new_title")?me->query("new_title"):me->query("title");
        if (stringp(title))
            str = sprintf("%s%s%s", title,(nick?"":" "), str);
    } // else

    if (!raw)
    {
        if ((int)query_temp("pending/exercise"))
        {
            force = me->query_skill_mapped("force");

            if (force) msg = SKILL_D(force)->exercise_msg(me);
            if (!msg || undefinedp(msg["status_msg"]))
                str = name() + "������������"NOR;
            else
                str = msg["status_msg"];
        } // if
        else if ((int)query_temp("pending/meditate"))
            str = name() + "������������"NOR;
    } // if

    if (!raw)
    {
        if (wizardp(me) && me->query("env/wizset"))
            str += " " + me->query("env/wizset") + NOR;
        if (userp(me))
        {
            if (me->is_net_dead())
            {
                switch (me->query("doing"))
                {
                    case "breakup":
                        str += HIY " <�չ���>" NOR;
                        break;
                    case "closed":
                        str += HIY " <������>" NOR;
                        break;
                    case "scheme":
                        str += HIW " <�ƻ���>" NOR;
                        break;
                    default:
                        str += HIG " <������>" NOR;
                } // switch
            } // if

            if (me->is_ghost())
                str = HIB "(����) " NOR + str;
            if (me->query("thief"))
                str += HIG " <����>" NOR;
            if (me->query_condition("no_pk_time"))
                str = HIR "(ͨ����) " NOR + str;
            if (me->query_condition("in_jail"))
                str = HIW "(����) " NOR + str;
            if (query_temp("doing_xiudao"))
                str += HIY " <�޵���>"NOR;
            if (me->query("env/invisibility"))
               str += HIW " <������>"NOR;
            if (in_input())
               str += HIC " <����������>" NOR;
            if (in_edit())
               str += HIY " <�༭������>" NOR;
        } // if

        if (interactive(me) &&
            query_idle(me) > 180 && !query_temp("ext_info") )
        {
            me->improve_skill("idle-force",1);
                str +=HIM"<����"+ chinese_number(query_idle(me)/60) + "����>" NOR;
        }
            if (me->is_fighting()) str += HIW " <ս����>" NOR;
            if (!living(me)) str += HIR + query("disable_type") + NOR;
    } // if

    return str;
}

varargs string long(int raw)
{
    string str, extra, *mask;
  
    if (!raw && sizeof(mask = query_temp("apply/long")))
        str = mask[sizeof(mask)-1];
    else if (!stringp(str = query("long")))
        str = short(raw) + "��\n";

    if (stringp(extra = this_object()->extra_long()))
        str += extra;

    return str;
}
