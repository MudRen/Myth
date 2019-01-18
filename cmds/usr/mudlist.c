// mudlist.c
// Modify By Mudring@SanJie

#include <ansi.h>
#include <net/daemons.h>
#include <net/macros.h>
#include <mudlib.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    mapping mud_list;
    mapping mud_svc;
    mixed   *muds;
    string  output;
    string  name;
    string  mudn;
    string  vis_mudn;
    string  local_mudlib;
    int     loop, size, total, count;

    if( !find_object(DNS_MASTER) )
        return notify_fail("��·���鲢û�б����롣\n");

    //  Obtain mapping containing mud data
    mud_list = (mapping)DNS_MASTER->query_muds();

    // so we recognise ourselves as a DNS mud
    mud_svc = DNS_MASTER->query_svc() + ([ Mud_name() : 0 ]);

    if(!mud_list)
        return notify_fail( MUD_NAME + "Ŀǰ��û�и���·������ Mud ȡ����ϵ��\n");

    //  Get list of all mud names within name server
    muds = keys( mud_list ) - ({ "DEFAULT" });

    if (!arg)
    {
        // filter for release sub sites & me
        local_mudlib = MUDLIB_NAME;
        muds = filter_array(muds, (: $(mud_list)[$1]["MUDLIB"] == $(local_mudlib) :));
    }
    else if (arg != "all")
        // filter for muds matched argument
        muds = filter_array(muds, (: sscanf($1, $(arg) + "%*s") :));

    if (! sizeof(muds))
        return notify_fail("Ŀǰ��վ��û�к���� MUD ȡ���κ���ϵ��\n");

    // Place mudlist into alphabetical format
    muds = sort_array(muds, 1);

    output = BRED HIG+"Mud        ��������                ������·λַ     �˿�  ����\n"+NOR;
    output += repeat_string("��", 32) + "\n";

    //      Count for users
    count = 0;

    for (loop = 0, size = sizeof(muds); loop < size; loop++)
    {
        mudn = muds[loop];
        if (undefinedp(mud_list[mudn]["USERS"]))
            continue;

        if (! stringp(name = mud_list[mudn]["MUDNAME"]))
            name = "δ֪����";

        // filter some ... strange ansi
        name = replace_string(name, ESC "[0;37;0m", "");
        name = replace_string(name, ESC "[2;17m", "");
        name = filter_color(name);

        // ��������
        vis_mudn = filter_color(mudn);
        if (strlen(vis_mudn) > 12) vis_mudn = vis_mudn[0..11];
        if (strlen(name) > 20) name = name[0..19];

        if (htonn(upper_case(mudn)) == htonn(upper_case(INTERMUD_MUD_NAME)))
        {
            mud_list[mudn]["HOSTADDRESS"] = LOCALHOST;
            output +=  BBLU+HIY;
        }
        else if (mud_list[mudn]["VERSION"] == MUDLIB_VERSION)
            output +=  GRN;
        else
            output += NOR;

        if (stringp(mud_list[mudn]["ZONE"]))
            name += "(" + mud_list[mudn]["ZONE"] + ")";

        output +=  sprintf("%-10s %-23s %-15s  %4s", 
                upper_case(vis_mudn), name,
                mud_list[mudn]["HOSTADDRESS"],
                mud_list[mudn]["PORT"]);

        if (!undefinedp(mud_list[muds[loop]]["USERS"]))
        {
            output+=sprintf("  %-4s", mud_list[mudn]["USERS"] );
            count += atoi(mud_list[mudn]["USERS"]);
        }
        else
            output+=sprintf("  ----", mud_list[mudn]["USERS"] );

        output +=NOR"\n";
        total ++;
    }

    //  Display dumped mudlist output through user's more pager
    output += repeat_string("��", 32) + "\n";

    if (! arg)
        output += "�������񻰡�����" + chinese_number(count) +
                  "λ�����" + chinese_number(total) + "��վ�������С�\n";

    if (objectp(me))
        me->start_more(output);
    else
        write(output + "\n");

    return 1;
}

int help()
{
    write("\nָ���ʽ��mudlist        �г������е�"MUD_NAME"վ�㡣\n"
        "      mudlist <MudName>  �г�ָ�� Mud ����Ϣ��\n"
        "      mudlist all        �г�Ŀǰ���������е� Mud��\n\n"
    );
    return 1;
}


